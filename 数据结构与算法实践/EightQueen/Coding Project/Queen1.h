const int max_board = 30;

class Queens {
public:

    Queens(int size); //   constructor
    bool is_solved() const;    //   is current configuration a solution ?
    void print() const;   //   print current configuration
    bool unguarded(int col) const;   //   is square free from attack ?
    void insert(int col); //   insert queen in row
    void remove(int col); //   remove queen from row

    int  board_size; //   dimension of board = maximum number of queens

private:
    int  count;      //   current number of queens = first unoccupied row
    bool queen_square[max_board][max_board]; //   is square free ?

};