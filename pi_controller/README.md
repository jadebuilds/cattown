# Raspberry Pi

## Functions

The Raspberry Pi in Cat Town performs a few key functions:

* Runs computer vision to detect the cat's location;
* Simulates mouse personalities to decide where the mice will run next;
* Decides when to deploy mice and which ones;
* Serves a user interface over the Web for remote viewing and control.


### Inter-Process Communication (IPC)

The Pi uses gRPC. The schema (`schema.proto`) defines the interface between services, and services use code-generated stubs
to send and receive data to each other. Stub generation is done as a little Python package in `/ipc`.

## Service Architecture

Each of these functions corresponds roughly to a service.

* The **Platform Manager** (`/platform_mgr`) tracks which mice are active, deploys new mice, 
* The Platform Manager runs a set of **Personalities** (`/personalities/*`) as [TODO some kind of package];
* The **Computer Vision System** (`/cv`) uses the camera to report the cat's location to Personalities;
* The **User Interface** is not yet started! See https://feline.atlassian.net/wiki/spaces/FES/pages/34045954/Local+Web+Server for the bounty :D

## Personalities 

RFC:

> There are a number of ways we could represent mouse personalities. The requirements as I see them are as follows:
>   * We'll want to run one personality for each mouse on the platform;
>   * We'll want to only run the personalities we need -- they might be expensive (ML models, custom computer vision);
>   * We'll need to provide simulation for developers to work on them locally;
>   * We'll need to provide some means of distributing them to platforms and keeping them up to date.
> 
> The best way I can think of is like this:
>   * Personalities are Python packages containing a class implementing MousePersonality;
>   * Personalities are dependency-injected into the Platform Manager using a config file, which calls into them;
>   * The user interface edits the config file when a kahu reloads the platform and inputs the mouse locations;
>   * Personalities are checked into Git; the Platform Manager pulls the Git repo and restarts itself to update.
>
> TODO finish me :) thx

### Future Functions

I really wanna see if we can detect mouse catches! I think that becomes an additional service.
The new entry above looks something like this:

* The **Platform Monitor** (`/monitor`) processes current sensor readings to detect events like mouse catches and stalls.

Note that this is pretty challenging to do, I think, especially with steppers because they do kinda constant motion. 
Could be really fun to run a local Timescale and synchronize it upstream somehow for analysis (I might tackle this in Root Systems!)


## Developer Resources

The Pi uses gRPC 