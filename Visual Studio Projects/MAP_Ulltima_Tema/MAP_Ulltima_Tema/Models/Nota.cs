using System;
namespace MAP_Ulltima_Tema
{
    public class Nota{
        private int ID;
        private int IDStudent;
        private int IDTema;
        private int nota;
        private String feedback;
        public Nota(int ID, int ids, int idt, int nota, String feedback){
            this.ID = ID;
            this.IDStudent = ids;
            this.IDTema = idt;
            this.nota = nota;
            this.feedback = feedback;
        }
        public int getID()
        {
            return this.ID;
        }
        public void setID(int entity)
        {
            this.ID = entity;
        }
    }
}
