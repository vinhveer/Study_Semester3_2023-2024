program Main;

var
  L, R, A, K, S, count: Int64;

begin
  count := 0;
  
  { Tắt đồng bộ hóa và giải buộc đầu vào/đầu ra }
  Val(paramstr(1), L);
  Val(paramstr(2), R);
  Val(paramstr(3), A);
  Val(paramstr(4), K);

  for S := L to R do
    if (A * S) mod K = 0 then
      Inc(count);

  Write(count);
end.
