/*
#include <algorithm>
#include <tuple>
#include <vector>

using namespace std;
int main () {
    class Job {
  public:
    int s;
    int e;
    int p;

    Job(int s1, int e1, int p1) {
      s = s1;
      e = e1;
      p = p1;
    }
  };

  class Solution {
  public:
    int jobScheduling(vector<int> &start, vector<int> &end, vector<int> &profit)
{ int n = start.size(); vector<Job> jobs; for (int i = 0; i < n; i++) { Job
j(start[i], end[i], profit[i]); jobs.push_back(j);
      }

      sort(jobs.begin(), jobs.end(), [&](Job A, Job B) -> bool {
        if (A.s == B.s)
          return A.e < B.e;
        return A.s < B.s;
      });

      sort(start.begin(), start.end());

      vector<int> profits(n, 0);

      for (int i = n - 1; i >= 0; i--) {
        int curr = 0;
        int next =
            lower_bound(start.begin(), start.end(), jobs[i].e) - start.begin();
        if (next == n) {
          curr = jobs[i].p;
        } else {
          curr = jobs[i].p + profits[next];
        }

        if (i == n - 1)
          profits[i] = curr;
        else
          profits[i] = max(curr, profits[i + 1]);
      }
      return profits[0];
    }
  };
}
*/