<?php

namespace Rector\DeadCode\Tests\Rector\Property\RemoveUnusedPrivatePropertyRector\OutsideAnonymousClass;

class SomeClass
{
    private $var;
    public function foo()
    {
        return new class
        {
            private $var;
            public function bar(){
                return $this->var;
            }
        };
    }
}
?>
-----
<?php

namespace Rector\DeadCode\Tests\Rector\Property\RemoveUnusedPrivatePropertyRector\OutsideAnonymousClass;

class SomeClass
{
    public function foo()
    {
        return new class
        {
            private $var;
            public function bar(){
                return $this->var;
            }
        };
    }
}
?>
