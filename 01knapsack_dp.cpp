#include <iostream>
#include <vector>
using namespace std;

struct Obj
{
    int id, wt, pr;
    Obj(int id, int pr, int wt)
    {
        this->id = id;
        this->pr = pr;
        this->wt = wt;
    }
};

int dp(vector<Obj*> obj, int n, int m)
{
    int **ans = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        ans[i] = new int[m + 1];
    }

    for (int i = 0; i < n; i++)
    {
        for (int w = 0; w < m + 1; w++)
        {
            if (i == 0 || w == 0)
            {
                ans[i][w] = 0;
            }
            else if (obj[i]->wt <= w)
            {
                ans[i][w] = max(ans[i - 1][w], ans[i - 1][w - obj[i]->wt] + obj[i]->pr);
            }
            else
            {
                ans[i][w] = ans[i - 1][w];
            }
            cout << ans[i][w] << " ";
        }
        cout << endl;
    }

    return ans[n - 1][m];
}

int main()
{
    int n, w;
    cout << "enter no of objects\n";
    cin >> n;
    vector<Obj *> obj;

    for (int i = 0; i < n; i++)
    {
        int pr, wt;
        cout << "enter profit and weight\n";
        cin >> pr >> wt;
        obj.push_back(new Obj(i, pr, wt));
    }
    cout << "enter total capacity\n";
    cin >> w;

    int profit = dp(obj, n, w);

    cout << "profit is : " << profit << endl;

    return 0;
}