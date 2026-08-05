# Permutizer

A C++ program that takes a name or word as input, calculates all possible letter arrangements, and identifies real English words from the results.

Built in Week 3 of learning C++ — now also live on the web.

**Try it:** https://againbuilds.github.io/Permutizer/frontend.html

---

## Why I built this

I've always been interested in the idea behind this kind of program — at its core, it's the same basis as a brute-forcer: generate every possible arrangement, then check which ones actually mean something. I was learning C++ at the time and wanted a real project to prove to myself what I'd actually learned, rather than just following tutorials. That's where Permutizer came from.

## Challenges

The main obstacle wasn't the C++ itself — it was not having consistent access to a laptop while building this. I worked around it by writing the code out by hand on paper, using OCR to digitize it, and using AI to help debug once it was typed up. That process is how I got from a paper draft to a working, GitHub-hosted program — and eventually to the live web version below.

---

## What it does

- Takes a word as input
- Calculates the total number of possible arrangements using factorial (n!)
- Generates every unique arrangement of the letters
- Loads a 370,000+ word English dictionary
- Outputs only real English words found from the arrangements

---

## How it works

The program uses three core concepts:

- **Factorial calculation** — counts total arrangements (n!)
- **next_permutation** — generates every arrangement systematically
- **unordered_set** — stores the dictionary for O(1) hash table lookup speed

---

## Web version

The site is a thin frontend on top of the real C++ program — no logic was reimplemented in JavaScript.

```
Browser (frontend.html)
   │  POST /permutize { "word": "cat" }
   ▼
Express API (server.js)
   │  runs the compiled binary as a subprocess
   ▼
permutizer.cpp  →  compiled binary  →  word.txt (370k+ word dictionary)
```

- **Frontend** — a static HTML/JS page, hosted free on GitHub Pages
- **Backend** — a small Express server that shells out to the compiled `permutizer` binary and returns its exact output. Hosted free on Render, built from the `Dockerfile` in this repo (installs g++, downloads the dictionary, compiles the binary, then starts the server)

Because the backend is on Render's free tier, it spins down after inactivity — the first request after a while can take up to ~50 seconds to wake back up.

---

## How to use (locally)

**Compile:**
```
g++ permutizer.cpp -o permutizer
```

**Run:**
```
./permutizer
```

**Example:**
```
Input: CAT

The number of arrangements is: 6

ACT
ATC
CAT
CTA
TAC
TCA

Real English words found:
ACT
CAT
```

---

## Running the web version yourself

1. Build and deploy `Dockerfile` as a Web Service (e.g. on Render) — it handles compiling and the dictionary download automatically
2. Update the `API_URL` constant near the top of `frontend.html`'s script to point at your deployed backend's `/permutize` endpoint
3. Host `frontend.html` anywhere static (GitHub Pages, Netlify, etc.)

---

## Requirements

- C++ compiler (GCC recommended)
- `words_alpha.txt` dictionary file in the same folder (named `word.txt` for the web backend)
- Download dictionary: https://github.com/dwyl/english-words

---

## Built with

- C++ (STL) — `algorithm` (sort, next_permutation), `unordered_set`, `fstream`
- Node.js / Express — API wrapper around the compiled binary
- Docker — reproducible build and compile step
- Render — backend hosting
- GitHub Pages — frontend hosting

---

## Author

**Again** — AgainBuilds
Started C++: 02/05/2026
github.com/AgainBuilds
