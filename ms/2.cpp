#include<iostream>
using namespace std;
int result[102];
int GetGrid(int width, int height)
{
    return width * height * (width - 1) * (height - 1) / 4;
}
void swap(int &N, int &M) 
{
    int temp = N;
    N        = M;
    M        = temp;
}
int main()
{
    int T, N, M, K;
    int i, j, width, height, max = 0;
    cin>>T;
    for (i = 0; i < T; ++i) {
        cin>>N>>M>>K;
	if (M > N) {
	    swap(M, N);
	}
	if (GetGrid(N, M) <= K) {
	    result[i] = GetGrid(N, M);
	    //cout<<GetGrid(N, M)<<endl;
	    continue;
	}
	max = 0;
	if (N >= M) {
	    for (width = 2; width <= M; ++width ) {
	        height = K / width;
	        if (height < width) break;
		if (K - width * N >= N) {
		    continue;
		} else if (K >= width * N){
                    int rest  = K - width * N;
		    int squar  = GetGrid(width, N) + GetGrid(rest, width + 1) - GetGrid(rest, width);
		    //cout<<width<<" "<<rest<<" "<<N<<" "<<squar<<endl;
		    max        = max > squar ? max : squar;
		    //cout<<"max1 = "<<max<<endl;
		} else {
                    int rest  = K - width * height;
		    int squar1 = GetGrid(width, height) + GetGrid(rest, height + 1) - GetGrid(rest, height);
		    int squar2 = GetGrid(width, height) + GetGrid(rest, width + 1) - GetGrid(rest, width);
		    int squar  = squar1 > squar2 ? squar1 : squar2;
		    max        = max > squar ? max : squar;
                    //cout<<"rest = "<<rest<<",width = "<<width<<",height = "<<height<<endl;
		    //cout<<"max2 = "<<max<<endl;
		}
	    }
	    //cout<<max<<endl;
	    result[i] = max; 
	} else {
	
	}
    }
    for (i = 0; i < T; ++i) {
	cout<<"Case #"<<i + 1<<": "<<result[i]<<endl;
    }
    return 0;
}
