import { onCall, HttpsError } from "firebase-functions/v2/https";
import * as logger from "firebase-functions/logger";
import { initializeApp } from "firebase-admin/app";
import { getFirestore, FieldValue } from "firebase-admin/firestore";

initializeApp();

const db = getFirestore();

export const addNewSoccerTeam = onCall(async (request) => {
  const { name, foundationYear } = request.data;

  if (!name || typeof name !== "string" || name.trim().length === 0) {
    throw new HttpsError("invalid-argument", "O nome do time é obrigatório.");
  }

  if (typeof foundationYear !== "number") {
    throw new HttpsError("invalid-argument", "O ano de fundação deve ser numérico.");
  }

  if (foundationYear < 1850 || foundationYear > new Date().getFullYear()) {
    throw new HttpsError("invalid-argument", "O ano de fundação é inválido.");
  }

  const docRef = await db.collection("soccerTeams").add({
    name: name.trim(),
    foundationYear,
    createdAt: FieldValue.serverTimestamp(),
  });

  logger.info("Novo time cadastrado", { id: docRef.id, name, foundationYear });

  return {
    message: "Time cadastrado com sucesso.",
    id: docRef.id,
  };
});

export const getSoccerTeams = onCall(async () => {
  const snapshot = await db
    .collection("soccerTeams")
    .orderBy("foundationYear", "asc")
    .get();

  const teams = snapshot.docs.map((doc) => ({
    id: doc.id,
    name: doc.data().name,
    foundationYear: doc.data().foundationYear,
  }));

  logger.info("Lista de times consultada", { total: teams.length });

  return { teams };
});