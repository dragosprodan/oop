using System;
using System.Collections.Generic;
namespace MAP_Ulltima_Tema{
    public interface CrudRepository<ID, E>{
        E findOne(ID id);
        List<E> findAll();
        E save(E entity);
    }
}
