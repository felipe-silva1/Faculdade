for i = 1:10
    for j = 1:6
        if i > j then A(i,j)=2*i
        elseif i < j then A(i,j)=i+j
        elseif i == j then A(i,j)=i-1
        end
    end
end

printf("A=\n")
disp(A)

printf("Soma dos elementos da 1º linha=%f\n",sum(A(1,:)))
printf("Elemento máximo da 4º coluna=%f\n",max(A(:,4)))
printf("Índices do máximo elemento da 4º coluna=")
disp(find(A(:,4) == max(A(:,4))))
