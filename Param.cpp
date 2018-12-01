void add(int *x, int a,int b,int c, int d){
    *x += a+b+c+d;
}
void do_math(int *x) {
  *x += 5;
}

int main(void) {
  int result = -1, val = 4;
  do_math(&val);
  add(&val, 1, 2, 3, 4);
  return result;
}
