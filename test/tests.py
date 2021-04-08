# Array of tests to run (in order)
# Each test contains
#   description - 
#   steps - A list of steps to perform, each step can have
#       inputs - A list of tuples for the inputs to apply at that step
#       *time - The time (in ms) to wait before continuing to the next step 
#           and before checking expected values for this step. The time should be a multiple of
#           the period of the system
#       *iterations - The number of clock ticks to wait (periods)
#       expected - The expected value at the end of this step (after the "time" has elapsed.) 
#           If this value is incorrect the test will fail early before completing.
#       * only one of these should be used
#   expected - The expected output (as a list of tuples) at the end of this test
# An example set of tests is shown below. It is important to note that these tests are not "unit tests" in 
# that they are not ran in isolation but in the order shown and the state of the device is not reset or 
# altered in between executions (unless preconditions are used).

tests = [ {'description':'PINA: 0x32 PINB: 0x32 PINC: 0x32 => PORTD: 0x01 ',
    'steps': [ {'inputs': [('PINA',0x32), ('PINB',0x32), ('PINC', 0x32)], 'iterations': 1 } ],
    'expected': [('PORTD', 0x01)],
    },
    {'description':'PINA: 0x35 PINB: 0x35 PINC: 0x35 => PORTD: 0x01 ',
    'steps': [ {'inputs': [('PINA',0x35), ('PINB',0x35), ('PINC', 0x35)], 'iterations': 1 } ],
    'expected': [('PORTD', 0x01)],
    },
    {'description':'PINA: 0x96 PINB: 0x00 PINC: 0xC0 => PORTD: 0x00 ',
    'steps': [ {'inputs': [('PINA',0x96), ('PINB',0x00), ('PINC', 0xC0)], 'iterations': 1 } ],
    'expected': [('PORTD', 0x00)],
    },
    {'description':'PINA: 0x51 PINB: 0x35 PINC: 0x00 => PORTD: 0x02 ',
    'steps': [ {'inputs': [('PINA',0x51), ('PINB',0x35), ('PINC', 0x00)], 'iterations': 1 } ],
    'expected': [('PORTD', 0x02)],
    },
    {'description':'PINA: 0x00 PINB: 0x00 PINC: 0x00 => PORTD: 0x00 ',
    'steps': [ {'inputs': [('PINA',0x00), ('PINB',0x00), ('PINC', 0x00)], 'iterations': 1 } ],
    'expected': [('PORTD', 0x00)],
    }  
     
    # {'description': 'PINA: 0x03 => PORTC: 0x02',
     #'steps': [ {'inputs': [('PINA', 0x03)], 'iterations': 1 }],
    # 'expected' : [('PORTC', 0x02)],
    # },
    # {'description': 'PINA: 0x07 => PORTC: 0x01',
    # 'steps': [ {'inputs': [('PINA', 0x07)], 'iterations': 1 }],
    # 'expected' : [('PORTC', 0x01)],
    #  },
   
]
#watch = ['PORTB'] # Set PIN to val then run one iteration
        
# Optionally you can add a set of "watch" variables these need to be global or static and may need
# to be scoped at the function level (for static variables) if there are naming conflicts. The 
# variables listed here will display everytime you hit (and stop at) at a breakpoint

