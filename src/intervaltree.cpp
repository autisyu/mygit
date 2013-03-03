#include<iostream>
using namespace std;
const int INF = 0x7ffffff;
const int cnt = 4;
int array[10000] = {4, 4, 5, 9, 31, 89, 90};
int dp[cnt][cnt + 1];
typedef struct Tnode {
int l, r, sum, v;
int mark;
struct Tnode* lc, *rc;
    Tnode()
    {
        lc = NULL, rc = NULL;
	mark = 0;
    }
}*pTnode;
pTnode root = NULL;
inline int Max(int a, int b)
{
    return a>b?b:a;
}
int Search(pTnode root, int sl, int sr);
int buildT(pTnode root)
{
    int l = root->l, r = root->r;
    if (r != l) {
        int mid =  l + ((r - l)>>1);
	root->lc = new Tnode();
	root->lc->l = l, root->lc->r = mid;
	root->rc = new Tnode();
	root->rc->l = mid + 1, root->rc->r = r;
        root->sum = buildT(root->lc) + buildT(root->rc);
	//cout<<l<<" "<<r<<" "<<root->sum<<endl;
	return root->sum;
    } else {
        root->sum = array[l];
        return array[l];
    }
}
int func()
{
    int i, len, k;
    for (i = 0; i < cnt; ++i) {
        dp[i][1] = 0;
    }
        for (len = 2; len <= cnt; ++len) {
            for (i = 0; i + len -1< cnt; ++i) {
	        dp[i][len] = INF;
	    for (k = 1; k < len; ++k) {
	        dp[i][len] = Max(dp[i][len], dp[i][k] + dp[i+ k][len - k] + Search(root, i, i + len - 1));
		cout<<"k = "<<k<<" "<<dp[i][k]<<" "<<dp[i+k-1][len -k]<<endl;
		cout<<"res = "<<i<<" "<<i + len -1<<" "<<Search(root, i, i + len -1)<<endl;
	    }
	} 
    }
    //for (i = )
    return dp[0][cnt];
}
int print_ans(int ans, int s, int len)
{
    //if (len == 1) cout<<s<<" ";
    for (int i = 1; i < len; ++i) {
        if (ans == Search(root, s, s + len - 1) + dp[s][i] + dp[s + i][len - i]) {
	    cout<<"("<<s<<" "<<i<<")("<<s+i<<" "<<len - i<<")"<<" "<<endl;
            print_ans(dp[s + i][len - i],s + i, len - i);
            print_ans(dp[s][i],s, i);
	    break;
	}
    }
}
int Update(pTnode root, int sl, int sr, int v)
{
    int l = root->l, r = root->r, mid = l + ((r - l)>>1);
    if (l == sl && sr == r) {
        root->mark += v;
        return root->mark * (root->r - root->l + 1) + root->sum;
    }
    //cout<<mid<<" "<<l<<" "<<r<<"== "<<sl<<" "<<" "<<sr<<endl;
    if (root->mark != 0) {
	    root->lc->mark = root->mark;
	    root->rc->mark = root->mark;
	    root->mark = 0;
	}
    root->sum += (sr - sl + 1) * v;
    if (mid >=sl && mid < sr ) {
	int lsm, rsm;
        lsm = Update(root->lc, sl, mid,v);
	rsm = Update(root->rc, mid+1, sr, v);
	return lsm + rsm;

    } else if (mid < sl) {
        return Update(root->rc, sl, sr, v);
    } else {
        return Update(root->lc, sl, sr, v);
    }
}
int Search(pTnode root, int sl, int sr)
{
    int l = root->l, r = root->r, mid = l + ((r - l)>>1);
    if (l == sl && sr == r) {
        return root->mark * (root->r - root->l + 1) * root->mark + root->sum;
    }
    //cout<<mid<<" "<<l<<" "<<r<<"== "<<sl<<" "<<" "<<sr<<endl;
    if (root->mark != 0) {
	    root->lc->mark = root->mark;
	    root->rc->mark = root->mark;
	    root->mark = 0;
	}

    if (mid >=sl && mid < sr ) {
        int lsm = Search(root->lc, sl, mid);
	int rsm =  Search(root->rc, mid+1, sr);
	return lsm + rsm;

    } else if (mid < sl) {
        return Search(root->rc, sl, sr);
    } else {
        return Search(root->lc, sl, sr);
    }
}

int main()
{
    for (int i = 0; i < cnt; ++i) {
        cout<<array[i]<<" ";
    }
    cout<<endl;
    root = new Tnode();
    root->l = 0, root->r = cnt - 1;
    buildT(root);
    int a, b;
    while (1) {
        cout<<"Search"<<endl;
        cin>>a>>b;
        cout<<Search(root, a, b)<<endl;
	cout<<"Update"<<endl;
	cin>>a>>b;
        cout<<Update(root, a, b, 1)<<endl;
    }

    /*cout<<root->sum<<endl;;
    while(1) {
        int l, r;
        cin>>l>>r;
        cout<<Search(root, l, r)<<endl;
    }*/
    //cout<<func()<<endl;
    //print_ans(dp[0][cnt], 0, cnt);
    /*for (int i = 0; i<cnt; ++i) {
        for (int j = 1; j<=cnt; ++j) {
	    cout<<dp[i][j]<<" ";
	}
	cout<<endl;
    }*/
    return 0;
}
