def atm_bnb(S, d):
    d.sort(reverse=True)

    def bnb(cur_amt, cur_d, cur_count):
        nonlocal best_count, best_sol
        lb = cur_count + (S - cur_amt) // d[cur_d[0]] if cur_d else 0  # Kiểm tra cur_d có rỗng hay không
        
        if lb >= best_count:
            return

        if cur_amt == S:
            best_count, best_sol = cur_count, cur_d.copy()
            return

        for i in range(len(d)):
            new_amt = cur_amt + d[i]
            if new_amt <= S:
                bnb(new_amt, cur_d + [i], cur_count + 1)

    best_count, best_sol = float('inf'), []
    bnb(0, [], 0)

    return best_sol

# Sử dụng ví dụ
S = 120
d = [1, 2, 5, 10, 20, 50]
result = atm_bnb(S, d)
print(result)
