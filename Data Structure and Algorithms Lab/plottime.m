Matrix=dlmread("time.txt");
[row,col]=size(Matrix);
noOfData=Matrix(2:row,1);
insSortTime=Matrix(2:row,2);
mergSortTime=Matrix(2:row,3);
plot(noOfData,insSortTime,"r");
%hold on;
figure;
plot(noOfData,mergSortTime,"b");