program matrixMul
   integer:: i, linha, coluna, elNumber
   integer, dimension(25) :: sizeElements
   real :: start, finish
   real, allocatable, dimension(:) :: x, b
   real, allocatable, dimension(:,:) :: A

   sizeElements = (/1000, 2000, 3000, 4000, 5000, 6000, &
   7000, 8000, 9000, 10000, 11000, 12000, &
   13000, 14000, 15000, 16000, 17000, 18000, &
   19000, 20000, 21000, 22000, 23000, 24000, &
   25000/)

   elNumber = size(sizeElements)
   !Criando Arquivo de Resultados
   open(1, file = 'fResultsLC.csv', status = 'new')
   write(1, *) "tamanho;tempo(10^-3 s)"
   !Loop de variacao de tamanho da matrix nxn
   do i = 1, elNumber
      ! Criando Matrizes A, x e b
      allocate(x(sizeElements(i)))
      allocate(b(sizeElements(i)))
      allocate(A(sizeElements(i), sizeElements(i)))
      !Populando Matrix A e vetor x com double aleatorios enter 0 e 1
      do linha = 1, sizeElements(i)
         x(linha) = rand()
         !Zerando elementos do vetor de resultados
         b(linha) = 0
         do coluna = 1, sizeElements(i)
            a(linha, coluna) = rand()
         end do
      end do
      !Operacao de multiplicacao matricial
      call cpu_time(start)
      do linha = 1, sizeElements(i)
         do coluna = 1, sizeElements(i)
            b(linha) = b(linha) + A(linha, coluna)*x(linha)
         end do
      end do
      call cpu_time(finish)
      !Termino da operacao de multiplicacao matricial
      write(1, *) sizeElements(i),";",(finish-start)*1000
      !Liberando memoria alocada
      deallocate(x)
      deallocate(b)
      deallocate(A)
   end do
   !Fechando Arquivo aberto
   close(1)

end program matrixMul