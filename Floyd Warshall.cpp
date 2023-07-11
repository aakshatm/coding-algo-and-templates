for (int k = 0; k < n; k++) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      matrix[i][j] = min(matrix[i][j],
                         matrix[i][k] + matrix[k][j]);
    }
  }
}
