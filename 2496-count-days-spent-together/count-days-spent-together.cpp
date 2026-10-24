class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        vector<int> days = {
            31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31
        };

        auto dayOfYear = [&](string date) {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));

            int total = day;
            for (int i = 0; i < month - 1; ++i) {
                total += days[i];
            }
            return total;
        };

        int aliceStart = dayOfYear(arriveAlice);
        int aliceEnd = dayOfYear(leaveAlice);
        int bobStart = dayOfYear(arriveBob);
        int bobEnd = dayOfYear(leaveBob);

        int overlapStart = max(aliceStart, bobStart);
        int overlapEnd = min(aliceEnd, bobEnd);

        return max(0, overlapEnd - overlapStart + 1);
    }
};