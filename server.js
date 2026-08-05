const express = require('express');
const cors = require('cors');
const { execFile } = require('child_process');
const path = require('path');

const app = express();
app.use(cors());
app.use(express.json());

const BINARY_PATH = path.join(__dirname, 'permutizer');

app.post('/permutize', (req, res) => {
  const word = (req.body && req.body.word ? String(req.body.word) : '').trim();

  if (!word) {
    return res.status(400).json({ error: 'Empty input!' });
  }
  if (!/^[a-zA-Z]+$/.test(word)) {
    return res.status(400).json({ error: 'Letters only, please.' });
  }
  if (word.length > 9) {
    return res.status(400).json({ error: 'Word too long — 9 letters or fewer (9! = 362,880 arrangements is already a lot).' });
  }

  execFile(BINARY_PATH, [word], { timeout: 15000, maxBuffer: 1024 * 1024 * 20 }, (err, stdout, stderr) => {
    if (err) {
      return res.status(500).json({ error: stderr.trim() || 'permutizer failed to run.' });
    }
    res.json({ output: stdout });
  });
});

app.get('/', (req, res) => {
  res.send('Permutizer API is running. POST /permutize with { "word": "cat" }');
});

const PORT = process.env.PORT || 3000;
app.listen(PORT, () => console.log(`Permutizer server listening on port ${PORT}`));
