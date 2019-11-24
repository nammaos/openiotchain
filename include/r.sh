

files=`ls nu_*`

for i 
	in $files
	
do
	
	echo $i
	

	name=`echo $i| awk -F'_' '{print $2}'`
	nname=oic_$name
	mv $i $nname
echo $nname
done
