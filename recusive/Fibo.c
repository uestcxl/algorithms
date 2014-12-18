/* 斐波纳契数列算法
 * 递归参数：n，返回值：前两个数的和
 * */

int Fibo(int n){
    return n<=2 ? 1 : Fibo(n-2)+Fibo(n-1);
}
