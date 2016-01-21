# Run this script to create the Vivado project files in the WORKING DIRECTORY
# If ::create_path global variable is set, the project is created under that path instead of the working dir

if {[info exists ::create_path]} {
	set dest_dir $::create_path
} else {
	set dest_dir [pwd]
}
puts "INFO: Creating new project in $dest_dir"

# Set the reference directory for source file relative paths (by default the value is script directory path)
set proj_name "bsd"

# Set the reference directory for source file relative paths (by default the value is script directory path)
set origin_dir ".."

# Set the directory path for the original project from where this script was exported
set orig_proj_dir "[file normalize "$origin_dir/proj"]"

set src_dir $origin_dir/src
set repo_dir $origin_dir/repo

# Create project
create_project $proj_name $dest_dir

# Set the directory path for the new project
set proj_dir [get_property directory [current_project]]

# Set project properties
set obj [get_projects $proj_name]
set_property "default_lib" "xil_defaultlib" $obj
set_property "board_part" "digilentinc.com:arty:part0:1.1" $obj
set_property "simulator_language" "Mixed" $obj
set_property "target_language" "VHDL" $obj

# Create 'sources_1' fileset (if not found)
if {[string equal [get_filesets -quiet sources_1] ""]} {
  create_fileset -srcset sources_1
}

# Create 'constrs_1' fileset (if not found)
if {[string equal [get_filesets -quiet constrs_1] ""]} {
  create_fileset -constrset constrs_1
}

# Set IP repository paths
set obj [get_filesets sources_1]
set_property "ip_repo_paths" "[file normalize $repo_dir]" $obj

# Add conventional sources
add_files -quiet $src_dir/hdl

# Add IPs
add_files -quiet [glob -nocomplain ../src/ip/*.xci]

# Add constraints
add_files -fileset constrs_1 -quiet $src_dir/constraints

# Mark timing_exc.xdc for LATE processing
# set_property "processing_order" "LATE" [get_files timing_exc.xdc]
# set_property target_constrs_file [get_files auto.xdc] [get_fileset constrs_1]

# Refresh IP Repositories
update_ip_catalog

# Create 'synth_1' run (if not found)
if {[string equal [get_runs -quiet synth_1] ""]} {
  create_run -name synth_1 -board_part "digilentinc.com:arty:part0:1.1" -flow {Vivado Synthesis 2015} -strategy "Flow_PerfOptimized_High" -constrset constrs_1
} else {
  set_property strategy "Flow_PerfOptimized_High" [get_runs synth_1]
  set_property flow "Vivado Synthesis 2015" [get_runs synth_1]
}
set obj [get_runs synth_1]
set_property "part" "xc7a35ticsg324-1L" $obj
set_property "steps.synth_design.args.fanout_limit" "400" $obj
set_property "steps.synth_design.args.fsm_extraction" "one_hot" $obj
set_property "steps.synth_design.args.keep_equivalent_registers" "1" $obj
set_property "steps.synth_design.args.resource_sharing" "off" $obj
set_property "steps.synth_design.args.no_lc" "1" $obj
set_property "steps.synth_design.args.shreg_min_size" "5" $obj

# set the current synth run
current_run -synthesis [get_runs synth_1]

# Create 'impl_1' run (if not found)
if {[string equal [get_runs -quiet impl_1] ""]} {
  create_run -name impl_1 -board_part "digilentinc.com:arty:part0:1.1" -flow {Vivado Implementation 2015} -strategy "Vivado Implementation Defaults" -constrset constrs_1 -parent_run synth_1
} else {
  set_property strategy "Vivado Implementation Defaults" [get_runs impl_1]
  set_property flow "Vivado Implementation 2015" [get_runs impl_1]
}
set obj [get_runs impl_1]
set_property "part" "xc7a35ticsg324-1L" $obj
set_property "steps.write_bitstream.args.bin_file" "1" $obj

# set the current impl run
current_run -implementation [get_runs impl_1]

puts "INFO: Project created:$proj_name"

# Comment the following section, if there is no block design
# Create block design
source $origin_dir/src/bd/system.tcl

# Generate the wrapper
set design_name [get_bd_designs]
make_wrapper -files [get_files $design_name.bd] -top -import

set obj [get_filesets sources_1]
set_property "top" "${design_name}_wrapper" $obj

puts "INFO: Block design created: $design_name.bd"

set scripts_vivado_version 2015.3
set current_vivado_version [version -short]

if { [string first $scripts_vivado_version $current_vivado_version] == -1 } {
   puts ""
   puts "WARNING: This script was generated in <$scripts_vivado_version> and is being run in <$current_vivado_version>. If any problems occur, retry running this script in Vivado <$scripts_vivado_version>."

   # return 1
}