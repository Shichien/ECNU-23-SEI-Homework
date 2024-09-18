为了便于调试和检查，类模板中的部分方法添加了Size检查，并提供操作是否成功的提示语。
程序中（CirQueue.cpp / CirQueue.h）预留了Debug()方法；
可以取消注释，以在运行时查看 Count、Rear、Front、Queue_Maxsize的数值。
// Debug();