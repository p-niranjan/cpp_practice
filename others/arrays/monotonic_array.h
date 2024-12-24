using namespace std;

bool isMonotonic(vector<int> array) {
  // Write your code here.
  bool isNinc = true;
  bool isNdec = true;
  for(int i = 1; i < array.size(); i++) {
    if(array[i] < array[i-1]) {
      isNdec = false;
    }
    if(array[i] > array[i-1]) {
      isNinc = false;
    }
  }
  return isNinc | isNdec;
}
