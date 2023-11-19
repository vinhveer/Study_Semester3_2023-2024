# Đọc dữ liệu vào
Xd, Xc, Td, Tc = map(int, input().split())

# Khởi tạo biến đếm tổng số ô kiểm soát
total_controlled_cells = 0

# Duyệt qua từng ô trên bàn cờ
for row in range(1, 9):
    for col in range(1, 9):
        # Kiểm tra xem ô đó có bị kiểm soát bởi quân tượng hoặc quân xe không
        if (row == Td and col == Tc) or (abs(row - Xd) == abs(col - Xc)) or (row == Xd or col == Xc):
            total_controlled_cells += 1

# In ra tổng số ô kiểm soát
print(total_controlled_cells)
