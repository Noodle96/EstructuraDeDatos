function [x] = gauss(A,b)
  n = length(A);
  for k=1:n-1
    for i=k+1:n
      m = A(i,k) / A(k,k);
      A(i,k) = 0;
      for j=k+1:n
        A(i,j) = A(i,j) - m*A(k,j);
      endfor
      b(i) = b(i)- m*b(k);
    endfor
  endfor
  
  x = zeros(n,1);
  x(n) = b(n) / A(n,n);
  
  for k=n-1:-1:1
    s = 0;
    for j=k+1:n
      s = s+ A(k,j) * x(j);
    endfor
    x(k) = b(k) -s / A(k,k);
  endfor
  
endfunction
