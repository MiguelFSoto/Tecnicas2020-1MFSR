& .\generator.exe
Write-Output "Running Bubble Sort v2"
& .\bubble.exe ordered.txt > data\obu.txt   
& .\bubble.exe unordered.txt > .\data\ubu.txt
#Write-Output "Running Selection Sort"
#& .\selection.exe ordered.txt > data\os.txt   
#& .\selection.exe unordered.txt > .\data\us.txt
#Write-Output "Running Merge Sort"
#& .\merge.exe ordered.txt > data\om.txt   
#& .\merge.exe unordered.txt > .\data\um.txt