# Docker orchestration

## Docker Swarm

### Points
- run all commands on master
- assign odd number of master 
- 

### command
- docker swarm init --in mananger node 
- docker node ls
- docker swarm join-token worker
- docker swarm leave
- docker node rm worker01


-to get worker details from manager: docker node inspect worker01

-to promote worker : docker node promote worker01 worker02

-