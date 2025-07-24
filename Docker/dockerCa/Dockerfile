FROM ubuntu

RUN apt-get update && \
    apt-get install -y curl && \
    curl -sL https://deb.nodesource.com/setup_18.x | bash - && \
    apt-get install -y nodejs && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /usr/app

COPY package*.json ./

RUN npm install

COPY . .

CMD ["node", "index.js"]
