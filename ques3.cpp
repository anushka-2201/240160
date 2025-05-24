int solve(vector<int> vect) {
#used countSort algorithm 
    int maxSize = 0;
    int n = vect.size();
    for(int i=0; i<n; i++) {
        if(vect[i]>maxSize) {
            maxSize = vect[i];
        }
    }
    vector<int> vect2(maxSize+1);
    for(int i=0; i<n; i++) {
        vect2[vect[i]]++;
    }
    for(int i=1; i<maxSize+1; i++) {
        vect2[i] = vect2[i]+vect2[i-1];
    }
    vector<int> finalV(n);
    for(int i=n-1; i>=0; i--) {
        vect2[vect[i]] = --vect2[vect[i]];
        int pos = vect2[vect[i]];
        finalV[pos] = vect[i];
    }
    for(int i=0; i<n; i++) {
        cout<<finalV[i];
    }
    return 0;
}