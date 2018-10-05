function ordenanacion_mayor_menor
 X=input('Inserte un vector: ');
 
 for i=1:length(X)
    [mayor,pos]=max(X(i:end));
    X((i-1)+pos)=X(i);
    X(i)=mayor;
    
 end
 disp(X); % Vector ordenado
  

endfunction
