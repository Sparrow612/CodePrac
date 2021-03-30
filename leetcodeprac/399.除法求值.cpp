/*
 * @lc app=leetcode.cn id=399 lang=cpp
 *
 * [399] 除法求值
 */

// @lc code=start
class DisjointSet
{
private:
    vector<double> weights;
    vector<int> parents;

public:
    DisjointSet(int n) : weights(n), parents(n)
    {
        for (int i = 0; i < n; i++)
        {
            parents[i] = i;
            weights[i] = 1.0;
        }
    }
    
    int find(int n)
    {
        if (n != parents[n])
        {
            int ori = parents[n];
            parents[n] = find(parents[n]);
            weights[n] *= weights[ori];
        }
        return parents[n];
    }

    void connect(int x, int y, double v)
    {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx == rooty) return;
        parents[rootx] = rooty;
        weights[rootx] = weights[y]*v / weights[x];
    }
    double isConnected(int i, int j)
    {
        int ip = find(i);
        int jp = find(j);
        if (ip == jp)
        {
            return weights[i] / weights[j];
        }
        return -1.0;
    }
};

class Solution
{
public:
    vector<double> calcEquation(vector<vector<string> > &equations, vector<double> &values, vector<vector<string> > &queries)
    {
        map<string, int> m;
        int id = 0;
        int n = equations.size();
        DisjointSet ds(2 * n);
        for (int i = 0; i < n; i++)
        {
            string a = equations[i][0], b = equations[i][1];
            if (m.find(a) == m.end())
            {
                m[a] = id++;
            }
            if (m.find(b) == m.end())
            {
                m[b] = id++;
            }
            ds.connect(m[a], m[b], values[i]);
        }
        vector<double> res;
        for (vector<string> &q : queries)
        {
            string s = q[0], e = q[1];

            if (m.find(s) == m.end() || m.find(e) == m.end())
            {
                res.push_back(-1.0);
            }
            else
            {
                res.push_back(ds.isConnected(m[s], m[e]));
            }
        }
        return res;
    }
};
// @lc code=end
