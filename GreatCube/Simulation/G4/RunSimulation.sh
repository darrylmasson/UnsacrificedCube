#! /bin/bash
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00000.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00000.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00001.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00001.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00002.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00002.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00003.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00003.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00004.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00004.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00005.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00005.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00006.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00006.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00007.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00007.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00008.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00008.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00009.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00009.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00010.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00010.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00011.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00011.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00012.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00012.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00013.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00013.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00014.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00014.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00015.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00015.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00016.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00016.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00017.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00017.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00018.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00018.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00019.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00019.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00020.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00020.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00021.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00021.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00022.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00022.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00023.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00023.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00024.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00024.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00025.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00025.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00026.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00026.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00027.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00027.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00028.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00028.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00029.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00029.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00030.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00030.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00031.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00031.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00032.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00032.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00033.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00033.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00034.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00034.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00035.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00035.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00036.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00036.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00037.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00037.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00038.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00038.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00039.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00039.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00040.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00040.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00041.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00041.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00042.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00042.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00043.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00043.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00044.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00044.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00045.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00045.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00046.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00046.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00047.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00047.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00048.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00048.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00049.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00049.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00050.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00050.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00051.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00051.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00052.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00052.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00053.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00053.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00054.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00054.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00055.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00055.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00056.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00056.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00057.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00057.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00058.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00058.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00059.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00059.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00060.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00060.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00061.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00061.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00062.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00062.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00063.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00063.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00064.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00064.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00065.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00065.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00066.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00066.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00067.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00067.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00068.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00068.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00069.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00069.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00070.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00070.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00071.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00071.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00072.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00072.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00073.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00073.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00074.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00074.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00075.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00075.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00076.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00076.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00077.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00077.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00078.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00078.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00079.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00079.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00080.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00080.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00081.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00081.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00082.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00082.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00083.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00083.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00084.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00084.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00085.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00085.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00086.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00086.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00087.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00087.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00088.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00088.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00089.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00089.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00090.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00090.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00091.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00091.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00092.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00092.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00093.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00093.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00094.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00094.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00095.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00095.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00096.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00096.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00097.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00097.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00098.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00098.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
LT1000="false"
while [ "$LT1000" = "false" ]
do
	TotalJobs=$(showq -u jpienaa | grep "Total jobs")
	TotalJobs=${TotalJobs:12:${#TotalJobs}}
	if [ $TotalJobs -gt 300 ]
	then
		sleep 10
	fi
	if [ $TotalJobs -lt 800 ]
	then
		LT1000=true
		if [ $TotalJobs -gt 500 ]
		then
			echo "More than 500 jobs. Waiting a minute before submission..."
			sleep 60
		fi
	else
		echo "Total jobs at"$TotalJobs". Waiting two minutes then trying again..."
		sleep 120
	fi
done
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00099.root 100000"
echo "~jpienaa/JP_Purdue/run_NGFlux_once /scratch/lustreC/j/jpienaa/Flux/NGZDepM700mm00099.root 100000" | qsub -l walltime=03:30:00
sleep 0.4
