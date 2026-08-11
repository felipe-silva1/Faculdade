bool isPrimo(int n) {
  if (n < 2) return false;
  for(int i = 2; i < n ~/ 2; i++) 
  {
    if(n % i == 0) return false;
  }
  return true;
}

void main() {
  for(int i = 0; i <= 100; i++) {
    if(isPrimo(i)) print('O número $i é primo.');
  }
}