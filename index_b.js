// INDEX BACKEND

const express = require("express");
const mongoose = require("mongoose");
const cors = require("cors");

const app = express();
app.use(cors());
app.use(express.json());


// Conexão com MongoDB
mongoose.connect(`mongodb+srv://admin:admin123@cluster0.8n4qwrm.mongodb.net/?retryWrites=true&w=majority&appName=Cluster0`, {
  useNewUrlParser: true,
  useUnifiedTopology: true,
});

// Definir schema e model
const UserSchema = new mongoose.Schema({
  name: String,
  email: String,
});
const User = mongoose.model('User', UserSchema);

// GET all users
app.get('/users', async (req, res) => {
  const users = await User.find();
  res.json(users);
});

// POST new user
app.post('/users', async (req, res) => {
  const { name, email } = req.body;
  const newUser = new User({ name, email });
  await newUser.save();
  res.json(newUser);
});

// DELETE user
app.delete('/users/:id', async (req, res) => {
  const { id } = req.params;
  const deleted = await User.findByIdAndDelete(id);
  if (!deleted) {
    return res.status(404).json({ message: "Usuário não encontrado" });
  }
  res.json({ message: "Usuário deletado com sucesso!", user: deleted });
});

app.listen(4000, () => console.log('🚀 Backend rodando em http://localhost:4000'));
