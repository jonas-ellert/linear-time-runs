#include <iostream>
#include "runs.hpp"

using std::cout;
using std::endl;

int main() {
  std::string strings[] = {
      "!bananatree!",
      "!mississippi!",
      "!011010110100101101011010!"
  };

  for (auto S : strings) {
    auto const R = linear_time_runs::compute_all_runs(S.data(), S.size());
    cout << "\nString " << S << " contains " << R.size() << " runs:" << endl;
    for (auto run : R) {
      cout << "pos=" << run.start
           << ", per=" << run.period
           << ", len=" << run.length
           << ", exp=" << run.length / (double) run.period
           << ", str=" << S.substr(run.start, run.length) << endl;
    }
  }
  return 0;
};