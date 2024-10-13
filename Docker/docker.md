
#  Docker Cmd

> **login** : docker login

> **Index** : https://app.eraser.io/workspace/yTPql82lXyOpbyX63Xgn

##  Links:

- **All docker images are available at** : [hub.docker.com](hub.docker.com)

## Attribute:

- **-it**: interactive, connect the main cmd to container cmd , and don't disconnect

- **-t**: tag (name)

  

##  Main Line cmd:

- **to make image/container** : install any image that will automatically make a container. **Cmd** : docker run -it ubuntu

- **to run any cmd inside container** : docker exec *container_name* ls. **eg:** docker exec pendatic_mendel ls

- **to see images** : docker images ls

- **Port mapping** : docker run -it p 1025:1025 container_name

- **Port mapping with evn set** : docker run -it -p 1025:1025(my_machine_Port:docker_port) -e key=value -e key=value continer_name. **eg** docker run -it -e PORT=4000 -p 4000:4000 first-nodejs

- **to build dockerfile** : docker build -t -image name you want to give- . (path)


##  Container cmd:

- **to see active** : docker container ls

- **to see all active** : docker container ls -a

- **to start container** : docker start -container name- , eg: docker start pedantic_mendel

- **to stop container** : docker stop pendatic_mendel

  

##  Dockerfile

save the file with name : "dockerfile" where package.json is present

    FROM ubuntu
    
    RUN apt-get update
    
    RUN apt-get install -y curl
    
    RUN apt-get upgrade -y
    
    RUN curl -sL https://deb.nodesource.com/setup_18.x | bash -
    
    RUN apt-get upgrade -y
    
    RUN apt-get install -y nodejs
    
      
    
    WORKDIR /usr/app
    
    COPY package.json package.json
    
    COPY package-lock.json package-lock.json
    
    COPY index.js index.js
    
      
    
    RUN npm install
    
      
    

Now run : docker build -t first-nodejs .

  

##  Layer caching

    Hello world

##  Docker compose

  

##  Docker network

> *we use it to connect two container under same network*

- **To show networks** : docker network ls

- **To inspect specific network**: docker network inspect milkyway

- **To create own network**: docker network create -d bridge -network_name- (eg: youtube)

- **To run on specific network**: docker run -it --network=milkyway --name wanda busybox
