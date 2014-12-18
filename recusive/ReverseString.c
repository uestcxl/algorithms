/*  判断是否为回文字符
 *  返回值：bool
 * */

bool ReverseString(char *a , int start , int end){
    if(start>=end)   return true;
    if(a[start++]!=a[end++])    return false;
    return ReverseString(*a,start,end);
}
