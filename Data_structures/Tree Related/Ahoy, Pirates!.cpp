#include <bits/stdc++.h>
using namespace std;

#define L(x) (1 + ((x) << 1))
#define R(x) (2 + ((x) << 1))
int const MAXN = 1024000 + 2;

struct node {
    node() {}
    node(int b, int e, int m, int v)
        : begin(b), end(e), mid(m), value(v) {}
    int begin, end, mid, value;
    char cmd;
};

struct segment_tree {
    vector<node> tree;

    segment_tree(int size) {
        tree = vector<node>(size << 2);
    }

    void init_tree(int index, int left, int right, bool values[]) {
        node& now = tree[index];
        now.begin = left, now.end = right;
        now.mid = (now.begin + now.end) >> 1;
        now.cmd = ' ';
        if (now.begin != now.end) {                 // get the values of the children
            init_tree(L(index), left, now.mid, values);
            init_tree(R(index), now.mid + 1, right, values);
            now.value = tree[L(index)].value + tree[R(index)].value;    // add the values of the children to the current node
        } else
            now.value = values[now.begin];
    }

    void set_node_update(int index, char cmd) {
        node& now = tree[index];
        if (cmd == 'I') {
            switch (now.cmd) {
                case 'E': now.cmd = 'F'; break;
                case 'F': now.cmd = 'E'; break;
                case 'I': now.cmd = ' '; break;
                case ' ': now.cmd = 'I'; break;
            }
        } else
            now.cmd = cmd;
    }

    void apply_update_values(int index) {
        node& now = tree[index];
        switch (now.cmd) {
            case 'E': now.value = 0; break;
            case 'F': now.value = now.end - now.begin + 1; break;
            case 'I': now.value = now.end - now.begin + 1 - now.value; break;
            case ' ': return;
        }
        set_node_update(L(index), now.cmd);
        set_node_update(R(index), now.cmd);
        now.cmd = ' ';
    }

    void update(int index, int left, int right, char cmd) {
        node& now = tree[index];
        if (now.begin >= left && now.end <= right)        // fits in interval
            set_node_update(index, cmd);                // update the command state
        apply_update_values(index);                     // must apply the updates on all nodes even if it isn't on the interval
        if (left > now.end || right < now.begin)      // doesn't fit in interval
            return;
        if (now.begin < left || now.end > right) {
            update(L(index), left, right, cmd);
            update(R(index), left, right, cmd);
            now.value = tree[L(index)].value + tree[R(index)].value;
        }
    }

    int query(int index, int left, int right) {
        node& now = tree[index];
        int result = 0;
        apply_update_values(index);
        if (now.begin >= left && now.end <= right) {
            result = now.value;
        } else if (left > now.end || right < now.begin) {
            result = 0;
        } else {
            result = query(L(index), left, right) + query(R(index), left, right);
            now.value = tree[L(index)].value + tree[R(index)].value;
        }
        return result;
    }
};

segment_tree tree(MAXN);
char pirates[100];
bool input[MAXN];

int main(int argc, char **args) {
    int TC; scanf("%d", &TC);
    for (int T = 1; TC-- > 0; ++T) {
        int M; scanf("%d", &M);
        int size = 0;
        while (M-- > 0) {
            int times; scanf("%d", &times);
            scanf("%s", pirates);
            int n = strlen(pirates);
            while (times-- > 0) {
                for (int i = 0; i < n; ++i)
                    input[size++] = pirates[i] == '1';
            }
        }
        tree.init_tree(0, 0, size - 1, input);
        printf("Case %d:\n", T);
        int query; scanf("%d", &query);
        int answer_index = 0;
        while (query-- > 0) {
            char c; cin >> c;
            int a, b; scanf("%d%d", &a, &b);
            if (c == 'S')
                printf("Q%d: %d\n", ++answer_index, tree.query(0, a, b));
            else
                tree.update(0, a, b, c);
        }
    }
    return 0;
}
