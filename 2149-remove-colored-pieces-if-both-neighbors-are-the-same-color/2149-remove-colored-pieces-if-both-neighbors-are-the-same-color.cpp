class Solution {
public:
    bool winnerOfGame(string colors) {
        map<char, int> m;
        for (auto i = colors.begin(); i != colors.end(); ) {
            char a = *i;
            auto b = i;
            while (b != colors.end() && *b == a) {
                b++;
            }
            m[a] += max(int(distance(i, b) - 2), 0);
            i = b;
        }

        if (m['A'] > m['B']) {
            return true;
        }
        return false;
    }
};