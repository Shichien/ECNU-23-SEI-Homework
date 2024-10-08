/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
    //根据布尔运算中的德摩根定律 A&B = !(!A | !B), 在限制条件下，无更优解
    return ~ ( ~x | ~y );
}

/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
    // LSB指的是最右端
    // 按照大端法，由于每个字节占8位，将X右移使得目标位到达最低位，与0xff = 1111 1111相与，即可将其他位置零
    return ( x >> ( n << 3 ) ) & 0xff ;
}

/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can astempe that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
	int AlgoRightShift = x >> n;
	int step1 = (1 << 31) >> n; 
	int step2 = step1 << 1;
	int step3 = ~step2;
	return AlgoRightShift & step3;
}

/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
    int m1 = 0x11 | (0x11 << 8);
    int Mask = m1 | (m1 << 16);
    int temp = x & Mask;
    temp += (x >> 1) & Mask;
    temp += (x >> 2) & Mask;
    temp += (x >> 3) & Mask;

    temp += (temp >> 16);

    Mask = (0xF << 8) | 0xF;
    temp = (temp & Mask) + ((temp >> 4) & Mask);
    temp = ((temp >> 8) + temp) & 0x3F;
    return temp;
}

/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
    // //只有输入为 0 的情况会进行特别处理，那么考虑 0 的相反数 是否是它本身
	int Step1 = (x | (~x) + 1);
	int Step2 = Step1 >> 31;
	int Step3 = ~Step2; //右移得到符号位，与1相与，若符号位为0，说明原码即为0，否则返回1.
    return Step3 & 1;
}

/* 
 * tmin - return minimum two'temp complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
    //  补码的最小值：10000.....
    return 1 << 31;
}

/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two'temp complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
	int Operation = 33 + ~n; // 32 - n;
	int Move = ((x << Operation) >> Operation);
	int Equal = Move ^ x; //如果和原来不一样，则返回1
	return !Equal ; 
}

/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
    int sign = 0, var = 0;
	sign = x >> 31;
	var = (1 << n) + (~0);
	return (x + (sign & var)) >> n; // 这一步是判断正数 Or 负数，若是正数，就直接右移n位，若是负数则加上了偏置值。
}

/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
    //  取补码 + 1 即可
    return ( ~ x ) + 1;
}

/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
    // 取符号位，是1就是负数
    int SignX = (x >> 31) & 1;
    return !((SignX) | !x);
}

/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
    int SignX = (x >> 31) & 1 ;
    int SignY = (y >> 31) & 1 ;
    int isSameSign = ! (SignX ^ SignY);
    int isEqual = !(x ^ y);
    int Res = (x + ((~y) + 1)) >> 31;
    return ( isEqual ) | (  (!( isSameSign ) & SignX ) | ( isSameSign & Res )  );
}

/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) { //二分查找
    int Tmp = 0;
	Tmp = (!!(x >> 16)) << 4; // 先查找左边16位中是否全为0，如果为0，就不动，如果有1，就回到左边16位中继续找
	Tmp = Tmp + ((!!(x >> (Tmp + 8))) << 3);    // 再判断8位（即17 - 24位），同理
	Tmp = Tmp + ((!!(x >> (Tmp + 4))) << 2);    // 再判断4位（即25 - 28位），同理
	Tmp = Tmp + ((!!(x >> (Tmp + 2))) << 1);    // 再判断2位（即29 - 31位），同理
	Tmp = Tmp + (!!(x >> (Tmp + 1)));           // 再判断最后1位（即第32位），最后返回Tmp的值
	return Tmp; // 该值则是最先出现的1的位置
}

/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int'temp, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
    unsigned M = (1 << 23) - 1; // 得到 11..111(23个1)，用来判断小数字段是否不为0
    unsigned Exp = 0xFF << 23; // 得到阶码全为1的数，左移是逻辑左移填充0，得到 1111 1111 0000...000（23位0）
    unsigned Checkpoint1 = (uf & M);  // 将尾数置零，是否小数字段不为0
    unsigned Checkpoint2 = (uf & Exp) == Exp; // 检查是否阶码部分都是1
    if ( Checkpoint2 && Checkpoint1 ) { // 若成立，返回Unsigned Float Value
        return uf;
    }
    // 否则直接取反
    return (1 << 31)^uf;
}

/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
	unsigned Answer;
    int Frac = 0;     // 尾数的小数部分
    int Delta = 0; // 用于进行舍入运算
    int Tail = 0;  // 存储尾数
    int FloatExp = 0;     // 存储指数

    // 优先进行特殊情况处理
    if (x == 0) return 0;  // 如果输入为0，则直接返回0
    if (x == 0x80000000) return 0xcf000000;  // 如果输入为0x80000000，则返回特定的值

    Answer = x & 0x80000000; // 提取符号位,此时Answer变量仍只表示符号位
    if (Answer) x = -x; //若 Answer 不为0，则返回负数（取绝对值）

    // 题目不给用for循环，那就用while，使得x一直移动到0时结束循环也可以。
    while ((x >> FloatExp)) FloatExp++;  // 计算出指数E
    FloatExp = FloatExp - 1;  // 修正，因为循环条件导致的会多一个。

    x = x << (31 - FloatExp);  // 将整数左移，得到尾数和舍入位
    Tail = (x >> 8) & 0x007FFFFF; // 获取尾数的23位
    Frac = x & 0xFF; // 获取被舍入的部分

    // 判断是否需要向上舍入
    Delta = (Frac > 128) || ((Frac == 128) && (Tail & 1));
    Tail += Delta;

    FloatExp = FloatExp + 127; // 按照浮点数的表示规则计算阶码的值

    // 检查尾数是否溢出
    if (Tail >> 23) {
        Tail = Tail & 0x007FFFFF;
        FloatExp += 1;
    }

    // 将符号位、阶码和尾数合并得到最终结果
    Answer = Answer | FloatExp << 23 | Tail;
    return Answer;  // 返回转换后的单精度浮点数表示
}

/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int'temp, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {

    unsigned SignFloat = uf & 0x80000000; //提取符号位
	unsigned ExpFloat = uf & 0x7F800000; //提取阶码位，掩码 0x7F800000 ：表示阶码全为1
    unsigned FracFloat = uf & 0x007FFFFF; //提取尾数位

	if (ExpFloat == 0) { //如果阶码位全为0，说明是非规格化数
		uf = ( FracFloat << 1 ) | SignFloat; // 尾数不变左移一位，再加上符号位。
	} else if ( ExpFloat != 0x7F800000) { // 如果阶码不全为1，则在阶码部分加上1，即可
		uf = uf + 0x800000;
    }
	return uf;
}