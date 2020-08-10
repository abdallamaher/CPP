<?php
/*
//duplicate same class in same namespace is syntax error
namespace Abdalla{
    class f{
       
    }
    class f{
       
    }
}    

//even this is error: namespaces with same name listen to each other
namespace Abdalla{
    class f{
       
    }
}
namespace Abdalla{
    class f{
       
    }
}

//namespaces don't accept variables
namespace Abdalla{
    $val = "me";    // error
    class f{
       
    }
}

so solution:
*/
namespace Abdalla{
    class f{
        function ge() {
            $t = "me";
          return $t;
        }
    }
}
namespace Abdalla\coms{
    class f{
        function ge() {
            $t = "meff";
          return $t;
        }
    }
}
namespace{
    echo Abdalla\f::ge();
    // echo Abdalla\f.ge(); error
    //echo Abdalla\f->ge(); error
}
?>
