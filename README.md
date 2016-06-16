## vcfsim
### v.0.1

vcfsim is a similarity analysis tool for vcf formatted files. 

It analyzes the similarity between two vcf files based on:
- Chromosome #
- position

#### Usage
vcfsim [path to vcf 1] [path to vcf 2]

#### Output
vcfsim reports the number of lines in file 1 that are and aren't in file 2. 
It also reports the number of lines in file 2 that are and aren't in 2.

Example output:
- number of lines of vcf1 in vcf2: 4635959
- number of lines of vcf1 not in vcf2: 147666
- number of lines of vcf2 in vcf1: 4635959
- number of lines of vcf2 not in vcf1: 169053

