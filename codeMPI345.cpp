if (rank < size/2) {
partner = rank + size / 2;
}
else {
partner = rank - size / 2;
}

 MPI_Status statusb[2];
MPI_Status status;
MPI_Request request[2];

char mess[7] = "Hola ";
mess[5] = '0' + rank;
mess[6] = '\0';
MPI_Isend(&mess, 7, MPI_CHAR, partner, 1, MPI_COMM_WORLD, &request[1]);
MPI_Irecv(&message, 7, MPI_CHAR, partner, 1, MPI_COMM_WORLD, &request[0]);
MPI_Waitall(2, request, statusb);
//MPI_Send(&mess, 7, MPI_CHAR, partner, 1, MPI_COMM_WORLD);
//MPI_Recv(&message, 7, MPI_CHAR, partner, 1, MPI_COMM_WORLD, &status);

 //printf(" He tardado %f segundos", tiempo);
//printf("Proceso %d, en el procesador %s. Cantidad de procesos %d\n", rank, name, size);
printf("[Proceso %d, companero %d] Mensaje recibido: %s", rank, partner, message);
printf("\n");