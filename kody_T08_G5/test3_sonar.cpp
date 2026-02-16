int process(int n) {
    if (n > 0) { printf("Positive"); }
    else { printf("Non-positive"); }  // duplikacja
    if (n > 0) { printf("Positive"); }  // zduplikowany kod, wysoka cyclomatic complexity
    return n;
}
