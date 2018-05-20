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
        String a, b;
        int f[][];
        int s[][];
        int index;

        public void solve(int testNumber, InputReader in, BufferedWriter out) throws IOException {
            int tc = in.nextInt();
            while(tc-- > 0) {
                a = in.readString();
                b = in.readString();
                f = new int [32][32];
                s = new int [32][32];
                index = 0;
                image1(0, 31, 0, 31);
                index = 0;
                image2(0, 31, 0, 31);
                int cnt = 0;

                for(int i = 0; i < 32; i++) {
                    for(int j = 0; j < 32; j++) {
                        cnt += (Math.max(f[i][j], s[i][j]));
                    }
                }
                out.write("There are " + Integer.toString(cnt) + " black pixels.\n");
            }
        }

        public void image1(int u, int d, int l, int r) {
            if(a.charAt(index) == 'p') {
                index++;
                image1(u, (u + d) / 2, (l + r) / 2 + 1, r);
                image1(u, (u + d) / 2, l, (l + r) / 2);
                image1((u + d) / 2 + 1, d, l, (l + r) / 2);
                image1((u + d) / 2 + 1, d, (l + r) / 2 + 1, r);
            } else if(a.charAt(index) == 'f') {
                fill1(u, d, l, r, 1);
                index++;
            } else if(a.charAt(index) == 'e') {
                fill1(u, d, l, r, 0);
                index++;
            } else {
                throw new RuntimeException();
            }
        }

        public void image2(int u, int d, int l, int r) {
            if(b.charAt(index) == 'p') {
                index++;
                image2(u, (u + d) / 2, (l + r) / 2 + 1, r);
                image2(u, (u + d) / 2, l, (l + r) / 2);
                image2((u + d) / 2 + 1, d, l, (l + r) / 2);
                image2((u + d) / 2 + 1, d, (l + r) / 2 + 1, r);
            } else if(b.charAt(index) == 'f') {
                fill2(u, d, l, r, 1);
                index++;
            } else if(b.charAt(index) == 'e') {
                fill2(u, d, l, r, 0);
                index++;
            } else {
                throw new RuntimeException();
            }
        }

        public void fill1(int u, int d, int l, int r, int cur) {
            for(int i = u; i <= d; i++) {
                for(int j = l; j <= r; j++) {
                    f[i][j] = cur;
                }
            }
        }

        public void fill2(int u, int d, int l, int r, int cur) {
            for(int i = u; i <= d; i++) {
                for(int j = l; j <= r; j++) {
                    s[i][j] = cur;
                }
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
