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

ENTRYPOINT ["node", "index.js"] 