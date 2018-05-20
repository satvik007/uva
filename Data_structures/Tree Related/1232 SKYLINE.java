package com.company;

import java.io.*;
import java.util.*;
import java.math.*;

/**
 * Actual solution is at the top
 * This was not generated using chelper.
 * @author Satvik Choudhary (satvik007)
 */

public class Main {
    public static void main(String[] args) throws IOException{
        /*
        // Use for stdio
        InputStream inputStream = System.in;
        OutputStreamWriter outputStream = new OutputStreamWriter(System.out);
        InputReader in = new InputReader(inputStream);
        BufferedWriter out = new BufferedWriter(outputStream);
        /*/
        //*
        // Use for fileio
        FileInputStream inputStream = new FileInputStream (new File("in.txt"));
        InputReader in = new InputReader(inputStream);
        FileWriter fileWriter = new FileWriter("out.txt");
        BufferedWriter out = new BufferedWriter(fileWriter);
        //*/
        satvik solver = new satvik();
        solver.solve(1, in, out);
        out.close();
    }

    static class satvik {
        public void solve(int testNumber, InputReader in, BufferedWriter out) throws IOException {
            int tc = in.nextInt();

            while(tc-- > 0) {
                int n = in.nextInt();
                int u, v, h;
                int ans = 0;
                SegmentTree cur = new SegmentTree(100010);

                for(int i = 0; i < n; i++) {
                    u = in.nextInt();
                    v = in.nextInt();
                    h = in.nextInt();
                    ans += cur.query(1, 0, 100010, u, v-1, h);
                    //out.write(Integer.toString(ans) + "\n");

                }
                out.write(Integer.toString(ans) + "\n");
            }
        }

        public class SegmentTree {
            public int tree[];
            public int n;

            public SegmentTree(int m) {
                n = m;
                tree = new int[4 * n];
            }

            public int query(int p, int l, int r, int i, int j, int h) {
                if(l != r && tree[p] != -1) {
                    tree[left(p)] = tree[p];
                    tree[right(p)] = tree[p];
                }
                if(l > j || r < i) return 0;
                if(l >= i && r <= j) {
                    if(l == r) {
                        if(tree[p] <= h) {
                            tree[p] = h;
                            return 1;
                        }
                        return 0;
                    } else if(tree[p] == -1) {
                        int ans = query(left(p), l, (l + r) / 2, i, j, h) + query(right(p), (l + r) / 2 + 1, r, i, j, h);
                        int a1 = tree[left(p)];
                        int a2 = tree[right(p)];
                        if(a1 == a2 && a1 != -1) {
                            tree[p] = a1;
                        } else
                            tree[p] = -1;
                        return ans;
                    } else {
                        if(tree[p] <= h) {
                            tree[p] = h;
                            return (r - l + 1);
                        }
                        return 0;
                    }
                }
                int ans = query(left(p), l, (l + r) / 2, i, j, h) + query(right(p), (l + r) / 2 + 1, r, i, j, h);
                int a1 = tree[left(p)];
                int a2 = tree[right(p)];

                if(a1 == a2 && a1 != -1) {
                    tree[p] = a1;
                } else {
                    tree[p] = -1;
                }
                return ans;
            }

            public int left(int p) {
                return (p << 1);
            }

            public int right(int p) {
                return (p << 1 | 1);
            }
        }

    }


    static class Util {
        static public int min(int a[], int left, int right) {
            int res = (1 << 30);
            for(int i = left; i < right; i++) {
                res = Math.min(res, a[i]);
            }
            return res;
        }

        static public int min(int a[]) {
            return min(a, 0, a.length);
        }

        static public boolean next_permutation(int[] p) {
            for (int a = p.length - 2; a >= 0; --a)
                if (p[a] < p[a + 1])
                    for (int b = p.length - 1;; --b)
                        if (p[b] > p[a]) {
                            int t = p[a];
                            p[a] = p[b];
                            p[b] = t;
                            for (++a, b = p.length - 1; a < b; ++a, --b) {
                                t = p[a];
                                p[a] = p[b];
                                p[b] = t;
                            }
                            return true;
                        }
            return false;
        }

        static public int max(int a[], int left, int right) {
            int res = -(1 << 30);
            for(int i = left; i < right; i++) {
                res = Math.max(res, a[i]);
            }
            return res;
        }

        static public int max(int a[]) {
            return max(a, 0, a.length);
        }

        static public int upper_bound(int[] a, int left, int right, int value) {
            int low = left;
            int high = right;
            while (low != high) {
                int mid = (low + high) / 2;
                if (a[mid] <= value) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }
            if (low == right) {
                return -1;
            }
            return low;
        }

        static public int lower_bound(int[] a, int left, int right, int value) {
            int low = left;
            int high = right;
            while (low != high) {
                int mid = (low + high) / 2;
                if (a[mid] < value) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }
            if (low == right) {
                return -1;
            }
            return low;
        }

        static public int upper_bound_rev(int[] a, int left, int right, int value) {
            while (left != right) {
                int mid = (left + right) >> 1;
                if (a[mid] < value) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            if (left < 0) {
                left *= -1;
            }
            return --left;
        }

        static public int lower_bound_rev(int[] a, int left, int right, int value) {
            while (left != right) {
                int mid = (left + right) >> 1;
                if (a[mid] <= value) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            if (left < 0) {
                left *= -1;
            }
            return --left;
        }
    }

    static class InputReader {

        private final InputStream stream;
        private final byte[] buf = new byte[8192];
        private int curChar, snumChars;
        private SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int snext() {
            if (snumChars == -1) {
                return -1;
                //throw new InputMismatchException();

            }

            if (curChar >= snumChars) {
                curChar = 0;
                try {
                    snumChars = stream.read(buf);
                } catch (IOException e) {
                    return -1;
                    //throw new InputMismatchException();
                }
                if (snumChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = snext();
            while (isSpaceChar(c)) {
                c = snext();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = snext();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = snext();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public long nextLong() {
            int c = snext();
            while (isSpaceChar(c)) {
                c = snext();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = snext();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = snext();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public int[] nextIntArray(int n) {
            int a[] = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = nextInt();
            }
            return a;
        }

        public int[][] next2dArray(int n, int m) {
            int a[][] = new int[n][m];
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    a[i][j] = nextInt();
                }
            }
            return a;
        }

        public String readString() {
            int c = snext();
            if(c == -1) {
                return null;
            }
            while (isSpaceChar(c)) {
                c = snext();
            }
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = snext();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public String nextLine() {
            int c = snext();
            if(c == -1) {
                return null;
            }
            while (isSpaceChar(c))
                c = snext();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = snext();
            } while (!isEndOfLine(c));
            return res.toString();
        }

        public boolean isSpaceChar(int c) {
            if (filter != null)
                return filter.isSpaceChar(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        private boolean isEndOfLine(int c) {
            return c == '\n' || c == '\r' || c == -1;
        }

        public int[] readIntArray(int size) {
            int[] array = new int[size];
            for (int i = 0; i < size; i++) {
                array[i] = nextInt();
            }
            return array;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);
        }
    }
}
