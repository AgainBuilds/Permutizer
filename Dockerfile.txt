FROM node:20-slim

# Install g++ to compile the C++ program, and curl to fetch the dictionary
RUN apt-get update && apt-get install -y g++ curl && rm -rf /var/lib/apt/lists/*

WORKDIR /app

# Install Node dependencies
COPY package.json .
RUN npm install --production

# Copy source files
COPY server.js .
COPY permutizer.cpp .

# Download the English word dictionary (370,000+ words)
RUN curl -L -o word.txt https://raw.githubusercontent.com/dwyl/english-words/master/words_alpha.txt

# Compile the original C++ program
RUN g++ -O2 permutizer.cpp -o permutizer

EXPOSE 3000
CMD ["node", "server.js"]
