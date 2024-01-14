vector<int> build_failure_function(const string& pattern) {
      int m = pattern.length();
      vector<int> lps(m, 0);
      int j = 0;

      for (int i = 1; i < m; ++i) {
          while (j > 0 && pattern[i] != pattern[j]) {
              j = lps[j - 1];
          }

          if (pattern[i] == pattern[j]) {
              ++j;
          }

          lps[i] = j;
      }

      return lps;
  }

  vector<int> kmp_search(const string& text, const string& pattern) {
      int n = text.length();
      int m = pattern.length();
      vector<int> lps = build_failure_function(pattern);
      vector<int> indices;
      int i = 0, j = 0;

      while (i < n) {
          if (pattern[j] == text[i]) {
              ++i;
              ++j;

              if (j == m) {
                  indices.push_back(i - j);
                  j = lps[j - 1];
              }
          } else {
              if (j != 0) {
                  j = lps[j - 1];
              } else {
                  ++i;
              }
          }
      }

      return indices;
  }
