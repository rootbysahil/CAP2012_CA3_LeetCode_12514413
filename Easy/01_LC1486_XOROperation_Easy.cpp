
#include <iostream>
using namespace std;

class Solution {
public:
int xorOperation(int n, int start) {

int ans = 0;

for (int i = 0; i < n; i++) {

int num = start + 2 * i;

ans = ans ^ num;
}

return ans;
}
};

int main() {

Solution s;

cout << s.xorOperation(5, 0);

return 0;
}
