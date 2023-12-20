# STLA_CPP
Stellantis_Training C++ Assignment

## LogcatParser
This application processes the logcat file and provides the following features:
1. Provide command line flags for applying various filtering mechanisms
2. Filter the logs by pid and vid. The user should be able to specify the pid and vid on
the command line
3. Filter by a time range. User should be able to specify the start and end time in
hh:mm::ss.ms format


### Build the Applications

The applications can be built with the following command:

```
make

```

### Run the Applications

The applications can be run inside the `./install/<preset>` directory by executing the following command:

```
./LogcatParser <logcat_file_path> [options]

```
Example:

To filter the logs for pid:
```
./LogcatParser <filename.log> --pid <pid_num>
```

To filter the logs for vid:
```
./LogcatParser <filename.log> --vid <vid_num>
```

To filter the logs within time range:
```
./LogcatParser <filename.log> --start <start_time> --end <end_time>
```
