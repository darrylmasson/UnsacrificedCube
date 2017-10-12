#!/usr/bin/python 

#*********************************************************************
#*This file produces a shell file with a list of commands that can be*
#*submitted to the cluster to do a simulation.                       *
#*                                                                   *
#*Things to remember: 1.) Change File Name                           *
#*                    2.) Number of files and events to simulate     *
#*                    3.) Run file depending on type of simulation   *
#*                    3.) Positioning of detectors                   *
#*                                                                   *
#*Check whether an energy calibration or flux measurement is being   *
#*calculated before setting options at step 3. For energy calibration*
#*Detector positioning must be adjusted in both the preinit macro and*
#*this file.                                                         *
#*                                                                   *
#*Remember to clear the scratch directory when a simulation is done. *
#*********************************************************************

#Set shell file and individual root output file parameters
outfile="/home/jpienaa/JP_Purdue/RunSimulation.sh"
file_name_base=["NGZDepM700mm"]
source_folder_loc=["~jpienaa/JP_Purdue/"]

#Location of file defining what MC and processing codes to use
#Options are: 1) Flux, 2) Energy
run_option="Flux"
if(run_option=="Energy"):
	save_dir="/scratch/lustreC/j/jpienaa/Energy/"
	run_file="run_NGEnergy_once"
	seperation = 1000
	angle = 20
	detector1 = 200
elif(run_option=="Flux"):
	save_dir="/scratch/lustreC/j/jpienaa/Flux/"
	run_file="run_NGFlux_once"

#Set number of events to simulate and number of files to be created
run_beamon = 100000
ranges_low=[0]
ranges_high=[100]


#Create shell file
import os,sys
file_array = os.listdir(save_dir)
F = open(outfile,"w+")

F.write("#! /bin/bash\n")
for j in range(0,1):
	run_string=source_folder_loc[j]+run_file
	for i in range(ranges_low[j],ranges_high[j]):
		stringnum = "%05d" % i
		testname = file_name_base[j] + stringnum + ".root"
		is_in=0
		for filename in file_array:
			if filename==testname:
				is_in=1
				break
			
		if (is_in==0):
			F.write("LT1000=\"false\"\n");
			F.write("while [ \"$LT1000\" = \"false\" ]\n") 
			F.write("do\n")
			F.write("\tTotalJobs=$(showq -u jpienaa | grep \"Total jobs\")\n")
			F.write("\tTotalJobs=${TotalJobs:12:${#TotalJobs}}\n")
			F.write("\tif [ $TotalJobs -gt 300 ]\n")
			F.write("\tthen\n")
			F.write("\t\tsleep 10\n")
			F.write("\tfi\n")
			F.write("\tif [ $TotalJobs -lt 800 ]\n")
			F.write("\tthen\n")
			F.write("\t\tLT1000=true\n")
			F.write("\t\tif [ $TotalJobs -gt 500 ]\n")
			F.write("\t\tthen\n")
			F.write("\t\t\techo \"More than 500 jobs. Waiting a minute before submission...\"\n")
			F.write("\t\t\tsleep 60\n")
			F.write("\t\tfi\n")
			F.write("\telse\n")
			F.write("\t\techo \"Total jobs at\"$TotalJobs\". Waiting two minutes then trying again...\"\n") 
  			F.write("\t\tsleep 120\n")
			F.write("\tfi\n")
			F.write("done\n")
			if (run_option=="Energy"):
				F.write("echo \"%s %s %d %s %d %d %d\"\n" % (run_string,save_dir+testname,run_beamon, file_name_base[j]+stringnum, seperation, angle, detector1))
				F.write("echo \"%s %s %d %s %d %d %d\" | qsub -l walltime=03:30:00\n" % (run_string,save_dir+testname,run_beamon,file_name_base[j]+stringnum, seperation, angle, detector1))
			elif (run_option=="Flux"):
				F.write("echo \"%s %s %d\"\n" % (run_string,save_dir+testname,run_beamon))
				F.write("echo \"%s %s %d\" | qsub -l walltime=03:30:00\n" % (run_string,save_dir+testname,run_beamon))
			F.write("sleep 0.4\n")
			#F.write("rm ~/JP_Purdue/STDIN.*\n")
			#F.write("sleep 0.4\n")
