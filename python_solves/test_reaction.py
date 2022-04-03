import reaction as solver

if __name__ == "__main__":
    INPUT_LINES = """

6
1
111
0
2
111 222
0 0
2
111 222
0 1
4
60 20 40 50
0 1 1 2
5
3 2 1 4 5
0 1 1 1 0
8
100 100 100 90 80 100 90 100
0 1 2 1 2 3 1 3




""".splitlines()
    INPUT_LINES = [line for line in INPUT_LINES if line]
    OUTPUT_LINES = """

Case #1: 111
Case #2: 333
Case #3: 222
Case #4: 110
Case #5: 14
Case #6: 490


""".splitlines()
    OUTPUT_LINES = [line for line in OUTPUT_LINES if line]


solver.run(INPUT_LINES=INPUT_LINES, OUTPUT_LINES=OUTPUT_LINES)

