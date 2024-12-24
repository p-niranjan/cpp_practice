using namespace std;

int bestSeat(vector<int> seats) {
  int bs = -1, l = 0, maxSpace = 0, avSpace = 0, N = seats.size(), r;
  while(l < N) {
    r = l+1;
    while(r < N && seats[r] == 0) {
      r++;
    }
    avSpace = r - l - 1;
    if(avSpace > maxSpace) {
      bs = (l+r)/2;
      maxSpace = avSpace;
    }
    l = r;
  }
  return bs;
}
