using namespace std;

vector<int> spiralTraverse(vector<vector<int>> m) {
  // Write your code here.
  int j = 0, sr = 0, er = m.size()-1, sc = 0, ec = m[0].size()-1;
  //vector<int> out;//((er+1)*(ec+1));
  //vector<int> out((er+1)*(ec+1));
  vector<int> out;
  while((sr <= er) && (sc <= ec)) {
    cout << "left to right\n";
    for(int i=sc; i<=ec; i++) {
      out.push_back(m[sr][i]);
      //out[j++] = m[sr][i];
      cout << m[sr][i] << " ";
    }
    cout << endl;

    cout << "right to bottom\n";
    for(int i=sr+1; i<=er; i++) {
      out.push_back(m[i][ec]);      
      //out[j++] = m[i][ec];
      cout << m[i][ec] << " ";
    }
    cout << endl;

    cout << "bottom to left\n";
    for(int i=ec-1; i>=sc; i--) {
      if(sr == er) {
        break;
      }
      out.push_back(m[er][i]);
      //out[j++] = m[er][i];
      cout << m[er][i] << " ";
    }
    cout << endl;

    cout << "left to up\n";
    for(int i=er-1; i>sr; i--) {
      if(sc == ec) {
        break;
      }
      out.push_back(m[i][sc]);
      //out[j++] = m[i][sc];
      cout << m[i][sc] << " ";
    }    
    cout << endl;
    sr++;
    sc++;
    er--;
    ec--;
    cout << "sr: " << sr << " sc: " << sc << " er: " << er << " ec: " << endl;
    // if(er == sr || ec == sc) {
    //   break;
    // }
  }
  return out;
}
